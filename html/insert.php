<?php 
//接收数据
var_dump($_POST);
$name = $_POST['user'];
$passwd =  $_POST['pwd'];
$link = @mysqli_connect('localhost','root','asd') or die('选择数据失败');
$r = mysqli_select_db($link,'class') or die('选择数据库失败');
mysqli_set_charset($link,'utf8');
$sql = "INSERT INTO user(user,passwd) values('{$name}','{$passwd}')";
$res = mysqli_query($link,$sql);
if($res && mysqli_affected_rows($link) > 0)
{
	echo '<script>alert("添加数据成功")</script>';
}
else 
{
	echo '<script>alert("添加数据失败")</script>';
}
?>
