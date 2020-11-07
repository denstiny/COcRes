<?php
$dbhost = 'localhost';
$dbuser = 'root';
$dbpass = 'asd';
$con = mysqli_connect($dbhost,$dbuser,$dbpass);
if(!$con)
{
	die('连接失败' . mysqli_error($con));
}
echo '链接成功';
$sql = ''
