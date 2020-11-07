<?php
var_dump($_POST);
$servername = "localhost";
$username = "root";
$password = "asd";
$name = $_POST['user'];
$passwd = $_POST['pwd'];
// 创建连接
$conn = new mysqli($servername, $username, $password) or die('连接数据库失败');
$re = mysqli_select_db($conn,'class') or die('选择数据失败');
mysqli_set_charset($conn,'utf-8');
$sql = "select * FROM user WHERE user='$name' and passwd='$passwd'";
$request = mysqli_query($conn,$sql);
if($request && mysqli_affected_rows($conn) > 0)
{
	echo '<script>alert("查询成功")</script>';
}
else{
	echo '<script>alert("查询失败")</script>';
}

$conn->close();
?>
