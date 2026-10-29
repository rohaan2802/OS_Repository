(function(){
  var root=document.documentElement;
  var themeBtn=document.getElementById('theme-toggle');
  function setTheme(t){root.setAttribute('data-theme',t);try{localStorage.setItem('os-theme',t)}catch(e){}
    themeBtn.setAttribute('aria-label',t==='dark'?'Switch to light theme':'Switch to dark theme');
    var m=document.querySelector('meta[name="theme-color"]');if(m)m.setAttribute('content',t==='dark'?'#0b1220':'#f8fafc');}
  setTheme(root.getAttribute('data-theme')||'light');
  themeBtn.addEventListener('click',function(){setTheme(root.getAttribute('data-theme')==='dark'?'light':'dark')});

  var menuBtn=document.getElementById('menu-toggle'),links=document.getElementById('nav-links');
  menuBtn.addEventListener('click',function(){var o=links.classList.toggle('open');menuBtn.setAttribute('aria-expanded',o)});
  links.addEventListener('click',function(e){if(e.target.tagName==='A'){links.classList.remove('open');menuBtn.setAttribute('aria-expanded','false')}});

  var navA=[].slice.call(links.querySelectorAll('a'));
  var secs=navA.map(function(a){return document.querySelector(a.getAttribute('href'))}).filter(Boolean);
  if('IntersectionObserver' in window){
    var spy=new IntersectionObserver(function(es){es.forEach(function(en){if(en.isIntersecting){navA.forEach(function(a){var on=a.getAttribute('href')==='#'+en.target.id;a.classList.toggle('active',on);if(on)a.setAttribute('aria-current','true');else a.removeAttribute('aria-current')})}})},{rootMargin:'-45% 0px -50% 0px'});
    secs.forEach(function(s){spy.observe(s)});
    var rv=new IntersectionObserver(function(es){es.forEach(function(en){if(en.isIntersecting){en.target.classList.add('in');rv.unobserve(en.target)}})},{rootMargin:'0px 0px -8% 0px'});
    document.querySelectorAll('.reveal').forEach(function(el){rv.observe(el)});
  }else{document.querySelectorAll('.reveal').forEach(function(el){el.classList.add('in')})}

  document.addEventListener('click',function(e){var b=e.target.closest('.btn');if(!b)return;
    var r=b.getBoundingClientRect(),s=Math.max(r.width,r.height),sp=document.createElement('span');
    sp.className='ripple';sp.style.width=sp.style.height=s+'px';sp.style.left=(e.clientX-r.left-s/2)+'px';sp.style.top=(e.clientY-r.top-s/2)+'px';
    b.appendChild(sp);setTimeout(function(){sp.remove()},650)});

  var top=document.getElementById('to-top');
  window.addEventListener('scroll',function(){top.classList.toggle('show',window.scrollY>700)},{passive:true});
  top.addEventListener('click',function(){window.scrollTo({top:0})});

  document.querySelectorAll('.code-wrap').forEach(function(w){
    var b=w.querySelector('.copy'),pre=w.querySelector('pre');
    b.addEventListener('click',function(){var c=pre.querySelector('code');var txt=(c||pre).innerText;
      (navigator.clipboard?navigator.clipboard.writeText(txt):Promise.reject()).then(function(){b.textContent='Copied!'},function(){b.textContent='Press Ctrl+C'});
      setTimeout(function(){b.textContent='Copy'},1600)})});

  var shots=[].slice.call(document.querySelectorAll('.shot'));
  var chips=[].slice.call(document.querySelectorAll('.chip'));
  var q=document.getElementById('search'),empty=document.getElementById('no-results');
  var cat='all';
  function filter(){var term=(q.value||'').trim().toLowerCase(),n=0;
    shots.forEach(function(s){var ok=(cat==='all'||s.dataset.cat===cat)&&(!term||s.textContent.toLowerCase().indexOf(term)>-1);s.classList.toggle('hide',!ok);if(ok)n++});
    document.querySelectorAll('[data-searchable]').forEach(function(el){var ok=!term||el.textContent.toLowerCase().indexOf(term)>-1;el.classList.toggle('hide',!ok);if(ok&&term&&el.tagName==='DETAILS')el.open=true});
    empty.style.display=n?'none':'block';}
  chips.forEach(function(c){c.addEventListener('click',function(){cat=c.dataset.filter;chips.forEach(function(x){x.setAttribute('aria-pressed',x===c)});filter()})});
  q.addEventListener('input',filter);

  var lb=document.getElementById('lightbox'),lbImg=lb.querySelector('img'),lbCap=lb.querySelector('p'),idx=0,lastFocus=null;
  function visible(){return shots.filter(function(s){return !s.classList.contains('hide')})}
  function show(i){var v=visible();if(!v.length)return;idx=(i+v.length)%v.length;var s=v[idx],im=s.querySelector('img');
    lbImg.src=s.dataset.full;lbImg.alt=im.alt;lbCap.textContent=(idx+1)+' / '+v.length+' — '+s.querySelector('figcaption').firstChild.textContent.trim();}
  function open(s){lastFocus=document.activeElement;show(visible().indexOf(s));lb.classList.add('open');document.body.style.overflow='hidden';lb.querySelector('.close').focus()}
  function close(){lb.classList.remove('open');document.body.style.overflow='';if(lastFocus)lastFocus.focus()}
  shots.forEach(function(s){s.querySelector('button').addEventListener('click',function(){open(s)})});
  lb.querySelector('.close').addEventListener('click',close);
  lb.querySelector('.prev').addEventListener('click',function(){show(idx-1)});
  lb.querySelector('.next').addEventListener('click',function(){show(idx+1)});
  lb.addEventListener('click',function(e){if(e.target===lb)close()});
  document.addEventListener('keydown',function(e){if(!lb.classList.contains('open'))return;
    if(e.key==='Escape')close();else if(e.key==='ArrowRight')show(idx+1);else if(e.key==='ArrowLeft')show(idx-1);
    else if(e.key==='Tab'){var f=[].slice.call(lb.querySelectorAll('button'));var i=f.indexOf(document.activeElement);e.preventDefault();f[(i+(e.shiftKey?-1:1)+f.length)%f.length].focus()}});
  var sx=0,sy=0;
  lb.addEventListener('touchstart',function(e){var t=e.changedTouches[0];sx=t.clientX;sy=t.clientY},{passive:true});
  lb.addEventListener('touchend',function(e){var t=e.changedTouches[0],dx=t.clientX-sx,dy=t.clientY-sy;
    if(Math.abs(dx)>50&&Math.abs(dx)>Math.abs(dy)*1.3)show(idx+(dx<0?1:-1));else if(dy>90&&Math.abs(dy)>Math.abs(dx)*1.5)close()},{passive:true});
})();
