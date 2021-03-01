数据库基本操作

一  数据库操作
        1.1  创建数据库
                 create database 数据库名 if not exists
        1.2  查看数据库
                 show databases;
                 show create database 数据库名
        1.3  选择数据库
                 use 数据库名
        1.4  删除数据库
                 drop database 数据库名 if  exists
             注释
                 单行注释 #或者--
                 多行注释 /* */


二  数据表操作
        2.1  创建数据表
                 create [temporary] table [if not exists] 表名
                 (字段名 字段类型 [字段属性] ...) [表选项]
        2.2  查看数据表
                 show tables
                 show tables like
        2.3  修改数据表
                 alter table 旧表名 [to/as] 新表名
                 rename table 旧表名1 to 新表名1 [,旧表名2 to 新表名2]
        2.4  查看表结构
                 desc 表名
                 show create table 表名
        2.5  修改表结构
                 alter table 表名 change 旧字段名 新字段名 字段类型 [字段属性]
                 alter table 表名 modify 字段名 新类型 [字段属性]
                 alter table 表名 modify 字段名 字段类型 [字段属性] [first/after 字段名]
                 alter table 表名 add 新字段名 字段类型 [first/after 字段名]
                 alter table 表名 drop 字段名

        2.6  删除表结构
                 drop [temporary] table [if exists] 表名1 [,表名2]

三  数据操作
        3.1  添加数据
                 为所有字段添加数据
                     insert into 表名 values （v1[,v2...]）;
                 为部分字段添加数据
                     insert into 表名(字段1[,字段2...]) values (v1[,v2...]);
                     insert into 表名 set 字段1=v1 [,字段2=v2];
                 一次添加多行数据
                     insert into 表名(字段1[,字段2...]) values (值列表1) ,(值列表2)...
        3.2  查询数据
                 查询表中全部数据
                     select * from 表名
                 查询表中部分字段
                     select (字段1 [,字段2...]) from 表名
                 简单条件查询数据
                     select * from 表名 where 字段名=值
        3.3  修改数据
                 update 表名 set 字段1=v1 [,字段2=v2...] [where 条件表达式];
        3.4  删除数据
                 delete from 表名 [where 条件表达式];
                 
                 
                 
                 
                 /* 2.1 数据库操作 */

# 创建一个名称为mydb的数据库
CREATE DATABASE idb;
CREATE DATABASE IF NOT EXISTS idb;

# 查看错误警告信息

SHOW WARNINGS;

# 查看MySQL服务器中已经存在的数据库
SHOW DATABASES;

# 查看创建mydb数据库的语句
SHOW CREATE DATABASE idb;

# 选择数据库
USE idb;

# 删除数据库
DROP DATABASE idb;
DROP DATABASE IF EXISTS idb;


# 此处填写单行注释内容，如：若服务器中没有mydb数据库，则创建，否则忽略此SQL
CREATE DATABASE IF NOT EXISTS idb;
-- 此处填写单行注释内容，如：若服务器中存在mydb数据库，则删除，否则忽略此SQL
DROP DATABASE IF EXISTS idb;

/* 
此处填写多行注释内容
如：利用以下SQL查看当前服务器中的所有数据库
*/

SHOW DATABASES;


/* 2.2 数据表操作 */

# ① 创建mydb数据库
CREATE DATABASE idb;
# ② 选择mydb数据库
USE idb;
# ③ 创建goods数据表
CREATE TABLE goods (
 id INT COMMENT '编号',
 name VARCHAR(32) COMMENT '商品名',
 price INT COMMENT '价格',
 description VARCHAR(255) COMMENT '商品描述'
);

CREATE TABLE t_stu (
sid INT(11),
sname VARCHAR(100) ,
gender char(10) ,
address VARCHAR(200)
);



# 省略②，修改③创建goods数据表
CREATE TABLE idb.goods (
 id INT COMMENT '编号',
 name VARCHAR(32) COMMENT '商品名',
 price INT COMMENT '价格',
 description VARCHAR(255) COMMENT '商品描述'
);

# 为mydb数据库再添加一张数据表new_goods
CREATE TABLE new_goods (
 id INT COMMENT '编号',
 name VARCHAR(32) COMMENT '商品名',
 price INT COMMENT '价格',
 description VARCHAR(255) COMMENT '商品描述'
);

# ① 查看所有数据表
SHOW TABLES;
# ② 查看名称中含有new的数据表
SHOW TABLES LIKE '%new%';


# 查看mydb数据库下含有new的数据表的详细信息
SHOW TABLE STATUS FROM idb LIKE '%new%'\G

# 将new_goods表的名称修改为my_goods
RENAME TABLE new_goods TO my_goods;
# 查看所有数据表
SHOW TABLES;

# ① 将my_goods数据表的字符集改为utf8
ALTER TABLE my_goods CHARSET = utf8;
# ② 查看修改结果
SHOW CREATE TABLE my_goods \G

# ① 所有字段
DESC my_goods;
# ② name字段
DESC my_goods name;

# 查看my_goods数据表的创建语句
SHOW CREATE TABLE my_goods \G

# 查看my_goods数据表结构的详细信息
SHOW FULL COLUMNS FROM my_goods;

# ① 将my_goods数据表中名为description的字段修改为des
ALTER TABLE my_goods CHANGE description des VARCHAR(255);
# ② 查看字段名的修改情况
DESC my_goods;

# ① 修改my_goods数据表中des字段的数据类型，将VARCHAR (255)修改为CHAR(255)
ALTER TABLE my_goods MODIFY des CHAR(255);
# ② 查看字段类型的修改情况
DESC my_goods des;

# ① 将my_goods表中最后一个字段des移动到name字段后
ALTER TABLE my_goods MODIFY des char(255) AFTER name;
# ② 查看字段位置的修改结果
DESC my_goods;

# ① 在my_goods数据表中字段name后新增一个num字段，表示商品的数量
ALTER TABLE my_goods ADD num INT AFTER name;
# ② 查看新增的字段
DESC my_goods;

# ① 删除my_goods数据表中num字段
ALTER TABLE my_goods DROP num;
# ② 看删除num字段后数据表中的字段
DESC my_goods;

# 删除数据表my_goods
DROP TABLE IF EXISTS my_goods;

/* 2.3 数据操作 */

# 为所有字段添加数据
INSERT INTO goods
VALUES (1, 'notebook', 4998, 'High cost performance');

# 添加含有中文的数据
INSERT  INTO goods
VALUES(2, '笔记本', 9998, '续航时间超过10个小时');

# 修改goods表中name和description字段的字符集
ALTER TABLE goods
MODIFY name VARCHAR(32) CHARACTER SET utf8,
MODIFY description VARCHAR(255) CHARACTER SET utf8;
	
# 为部分字段添加数据	
INSERT INTO goods (id, name) VALUES (3, 'Mobile phone');
INSERT INTO goods SET id = 3, name = 'Mobile phone';	
	
# 一次添加多行数据
INSERT  INTO goods VALUES
(1, 'notebook', 4998, 'High cost performance'),
(2, '笔记本', 9998, '续航时间超过10个小时'),
(3, 'Mobile phone', NULL, NULL);

# 查询表中全部数据	
SELECT * FROM goods;

# 查询表中部分字段
SELECT id, name FROM goods;

# 简单条件查询数据
SELECT * FROM goods WHERE id = 1;
	
# 将goods表中编号为2的商品价格由9998元修改为5899元。	
UPDATE goods SET price = 5899 WHERE id = 2;	
# 查看编号为2的商品价格修改情况
SELECT * FROM goods WHERE id = 2;	
	
	
# 删除goods表中编号等于3的商品数据
DELETE FROM goods WHERE id = 3;
# 查询goods表中记录的变化
SELECT * FROM goods;


/* 动手实践1 */

#创建表
  create table t_stu(
    sid int,
    sname varchar(100),
    gender char(10),
    address varchar(200)
  );

#更新表结构
  alter table t_stu modify sname char(100);
  alter table t_stu modify gender varchar(10);
  alter table t_stu modify address char(200);

#插入数据
alter table t_stu modify sname char(100) character set utf8;
alter table t_stu modify gender varchar(10)  character set utf8;
alter table t_stu modify address char(200)  character set utf8;

insert into t_stu values (1,'张三','女','南昌');
insert into t_stu values (2,'李四','男','南京');
insert into t_stu values (3,'王二','女','北京');
insert into t_stu values (4,'李鬼','女','徐州');
insert into t_stu values (5,'李贵','男','安徽');

#更新数据
update t_stu set gender='男' where sid=1;
update t_stu set gender='女' where sid=2;
update t_stu set gender='男' where sid=3;
update t_stu set gender='男' where sid=4;
update t_stu set gender='女' where sid=5;

#删除数据
delete from t_stu where sid=1;
delete from t_stu where sid=2;
delete from t_stu where sid=3;
delete from t_stu where sid in (1,2,3);



/* 动手实践2 */

# 选择数据库
CREATE DATABASE IF NOT EXISTS mydb;

# 创建电子杂志订阅表
CREATE TABLE subscribe (
 id INT COMMENT '编号',
 email VARCHAR(60) COMMENT '邮件订阅的邮箱地址',
 status INT COMMENT '是否确认，0未确认，1已确认',
 code VARCHAR(10) COMMENT '邮箱确认的验证码'
) DEFAULT CHARSET=utf8;

# 添加数据
INSERT INTO subscribe VALUES
(1, 'tom123@163.com', 1, 'TRBXPO'),
(2, 'lucy123@163.com', 1, 'LOICPE'),
(3, 'lily123@163.com', 0, 'JIXDAMI'),
(4, 'jimmy123@163.com', 0, 'QKOLPH'),
(5, 'joy123@163.com', 1, 'JSMWNL');
# 查询所有数据
SELECT * FROM subscribe;
	
# 查看已经通过邮箱确认的电子杂志订阅信息	
SELECT * FROM subscribe WHERE status = 1;

# 将编号等于4的确认状态设置为已确认。
UPDATE subscribe SET status = 1 WHERE id = 4;
# 查看编号等于4的记录修改后的信息
SELECT * FROM subscribe WHERE id = 4;

# 删除编号等于5的电子杂志订阅信息
DELETE FROM subscribe WHERE id = 5;
# 查看删除数据后表中的数据
SELECT * FROM subscribe;
