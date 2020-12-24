(function () {
  var mySwiper = new Swiper('.banner .swiper-container', {
    speed: 1000,
    loop: true,

    autoplay: {
      delay: 1000,
      disableOnInteraction: false,
    },

    effect: 'slide',

    pagination: {
      el: '.swiper-pagination',
      clickable: true
    },

    navigation: {
      nextEl: '.swiper-button-next',
      prevEl: '.swiper-button-prev',
    },
  })
})();

(function () {
  var mySwiper = new Swiper('.news_info .swiper-container', {
    direction: 'vertical',
    speed: 1000,
    loop: true,

    autoplay: {
      delay: 1000,
    },

    effect: 'slide',

  })
})();

(function () {
  var ul = document.querySelector('.seckill_content ul');
  var lis = ul.children;
  ul.style.width = lis[0].offsetWidth * lis.length + 'px';
})();

(function () {
  var myScroll = new IScroll('.seckill_content', {
    scrollX: true,
    scrollY: false,
  })
})();