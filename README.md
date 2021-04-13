## 沐浴  


<head>
<meta charset="utf-8">

<script type="text/javascript">
var paper = "人永远在追求快乐 ，永远在逃避痛苦 。";
var count = 1;
function oneByOne() {
	var screen = paper.substr(0, count);
	loopText.innerHTML = screen;
	count++;
	if (count > paper.length) {
		count = 0;
	}
	setTimeout(oneByOne, 250);
}
onload = oneByOne;
</script>
<style type="text/css">
#test {
	position: absolute;
right: 6em;
top: 1em;
width: 1px;
color: #ff0000;
	   font-size: 20px;
	   font-weight: bold;
}
</style>


<style>
.img1 {
height: auto;
width: auto;
}

body {
	/*去除滚动条*/
	overflow-x: hidden;
width: 100%;
height: 100%;
		background-image: url('https://s3.ax1x.com/2021/01/05/sFiSqf.jpg');
		background-size: cover;
		background-attachment: fixed;
}

.head {
position: absolute;
left: 0;
top: 0;
right: -17px;
bottom: 0;
		overflow-x: hidden;
		overflow-y: scroll;
}

.div1 {
margin: 0 auto;
width: 150px;
height: 150px;
		background-image: url('http://q1.qlogo.cn/g?b=qq&nk=2254228017&s=640');
		background-size: cover;
		border-radius: 50%;
display: flex;
		 margin-top: 350px;
animation: myfirst 3s;
		   -webkit-animation: myfirst 5s infinite linear;

}

@keyframes myfirst {
	0% {
		/*transform: scale(1)*/
		margin-top: 350px;
	}

	25% {
transform: scale(1.1);
		   /*放大1.1倍*/
		   margin-top: 300px;
	}

	50% {
transform: scale(1);
	}

	75% {
transform: scale(1.1);
	}

	100% {

transform: scale(1.1);
	}
}

.font {
margin: 0 auto;
		margin-top: 30px;
		text-align: center;
		font-size: 25px;
		font-family: 'Times New Roman';
		text-decoration: blink;
color: rgb(229, 233, 236, 0.5);
transition: all 1s;
}

.font:hover {
transform: scale(1.2, 1.2);
color: antiquewhite;
}

a {
	text-decoration: none;
color: rgb(229, 233, 236);
}

.lastDiv {
	margin-top: 100%;
	text-align: center;
color: rgb(225, 225, 228);
}

.gey{
	font-size: 20px;
	align-items: center;
color:rgb(175, 194, 211);
}
.none {
width: 500px;
height: 300px;
margin: 0 auto;
		border-radius: 5%;
		margin-top: 90px;
		background-color: rgb(117, 117, 126, 0.4);
		text-align: center;
}

.end {
float: left;
color: rgba(253, 249, 240, 0.5);
	   margin-top: 20px;
	   line-height: 5px;
	   margin-left: 20px;
width: 30px;
height: 10px;
transition: all, 3s;
}

#en:hover {
transform: rotate(360deg);
color: red;
}
</style>
</head>

<body>
<div class="end" id="en">
<b>—</b>
<b>—</b>
<b>—</b>
</div>
<div class="head">
<div class="div1">
</div>
<div class="none">
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<font class="gey">遇到bug就是遇到机会，当我独立解决他我将得到提升</font>
</div>
<div class="font">
<a class="a1" href="http://wpa.qq.com/msgrd?v=3&uin=2254228017&site=qq&menu=yes">QQ </a>&nbsp;

<a class="a2" href="https://space.bilibili.com/449364077">
<font>bilibili</font>
<a class="a2" href="http://denstiny.qjty.xyz/">
<font>博客</font>
</a>
<a class="a2" href="https://github.com/denstiny">
<font>Github</font>
</a>
</div>
<div class="lastDiv"><u>版权所有 By:迟早 江西先锋软件学院</u></div>

</div>
<div id="test">
<p id="loopText"></p>
</div>
</body>

</html>

