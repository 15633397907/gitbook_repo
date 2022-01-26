# PartⅠ Git




* [Chapter 1 gitbook使用心得](cpt01_gitbook/README.md)
  
  * [Section1.1 gitbook安装](cpt01_gitbook/01_gitbook_install.md)
    
  * [Section1.2 gitbook命令](cpt01_gitbook/02_gitbook_use.md)

* [Chapter 2 git使用心得](cpt02_git/README.md)
  
  * [Section2.1 git常用命令](cpt02_git/01_git_command.md) 
    
  * [Section2.2 git下拉远程库](cpt02_git/02_git_pull_clone.md)


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
