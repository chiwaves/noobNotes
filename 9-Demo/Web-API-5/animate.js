//  element:需要移动的元素
//  target：要移动到哪里
function animate(element,target) {

  clearInterval(element.timeId);

  // 需要让div自动移动——》定时器
  element.timeId = setInterval(function () {
    var current = element.offsetLeft;
    var step = ( target - current ) / 10;
    step = step > 0 ? Math.ceil(step) : Math.floor(step);
    current += step;
    element.style.left = current + 'px';

    // 判断如果当前的位置来到了目标位置——》400，此时清除定时器
    if ( current === target ) {
      clearInterval(element.timeId);
    }
  },16)
}