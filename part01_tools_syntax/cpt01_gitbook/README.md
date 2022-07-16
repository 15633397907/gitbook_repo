# Chapter.1 Gitbook

记录了gitbook安装过程及一些常用命令。

* [Section 1.1 gitbook安装](01_gitbook_install.md)
* [Section 1.2 gitbook使用](02_gitbook_use.md)

参考[GitBook 简明教程](https://www.chengweiyang.cn/gitbook/)

[Gitbook文档](https://docs.gitbook.com/)

<script type="text/javascript">
window.addEventListener("load", function() {
  var click_handle = function() {
    if (this.href.substr(-5) == ".html") {
      location.href = this.href;
    } else {
      location.href = "./index.html";
    }
  };
  var as = document.querySelectorAll(".chapter a, .navigation-prev, .navigation-next");
  for (var i = 0; i < as.length; i++) {
    as[i].addEventListener("click", click_handle, true);
    as[i].title = as[i].innerText;
  }
});
</script>