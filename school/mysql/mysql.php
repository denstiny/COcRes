<?php
$servername = "127.0.0.1";
$username = "root";
$password = "asd";
$name = trim(fgets(STDIN));
$conn = new mysqli($servername,$username,$password) or die('连接数据库失败')
$re = mysqli_select_db($conn,'class') or die('选择数据失败');
#$sql = "select * FROM stud WHERE name='$name' and passwd='$passwd'";
$request = mysqli_query($conn,$sql);
$request = mysqli_query($conn,$sql);
if($request && mysqli_affected_rows($conn) > 0)
{
    echo '<script>alert("登录成功")</script>';
    header('location:header.html');
}
else{
    echo '<script>alert("登录失败")</script>';
}

$conn->close();

?>
