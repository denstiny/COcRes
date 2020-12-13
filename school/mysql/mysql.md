show databases 显示数据库  
create databases 创建一个数据库
create databases DB_NAME charset=utf9; 创建一个数据库，并指定编码方式;  
 drop database DB_NAME; 删除数据库;  
 use DB_NAME;  使用指定的数据库
 create table TABLE_NAME(表类型)  

create table stu(id int primary key auto_increment,name text,eage int);   创建一个表，并指定表的类型;  
insert into TABLE_NAME values(数据) 插入表数据;  
desc TABLE_NAME;  查询表数据类型  
-- show create TABLE_NAME;  
select * form TABLE_NAME; 查询数据   
show tables;  查询数据库所有表
delete from  TABLE_NAME ；删除数据   

select sname form student; 单列查询  
select sname,sno,sgentle form student;  多列查询  
truncate tabel tabele_name; 删除表  

alter table tabele_name 字段 新字段名 类型  
alter table tabele_name add 字段名 字段类型
alter table class change descr koa varchar(20); 修改表单数据   
alter table 表名 alter column 字段名 drop default; 修改表单的默认数据  
alter table 表明 modify 字段名 init unsingned;  

alter table tabele_name MODIFY 字段名 新字段类型  
alter table t_stu MODIFY COLUMN gender varchar(10); 修改表单数据  
default current_timestamp on update current_timestamp,  

修改表单某一列的值   
update t_stu sid=1 where snmae='张三'  
         |     |               |
		表名 修改表单数据   过滤条件  

数据类型  
1)  数字类型
             整数类型 tinyint smallint mediumint int bigint  
             浮点数类型 float double  
             定点数类型 decimal  
             BIT类型 bit  
2)  时间和日期类型
             YEAR '2020'  
             DATE  '2020-02-02'  
             TIME  '11:30:50'
             DATETIME '2014-01-22 12:02:02'  
             TIMESTAMP '2014-01-22 12:02:02'
							current_date  当前日期 now() 当前时间   
2001-01-01 15:10:22
YYYY-MM-DD HH:MM:SS  
							current_time 当前时间
							CURRENT_TIMESTAMP 当前时间戳  
3)  字符串类型
             char和varchar  文本数据 前者存储空间固定 后者变化  
             TEXT 大文本数据  
             ENUM 枚举类
             SET  集合类  
             BINARY和VARBINARY  二进制数据 前者存储空间固定 后者变化  
             BLOB 大二进制数据  
4)  JSON类型
             本质是字符串  
             JSON数组和JSON对象
                 "{1,'abc',null,true}"  
                 "{'name':'张三','age':40}"  
表的约束
1)  默认约束  
           字段名 数据类型 default 默认值  
2)  非空约束
           字段名 数据类型 not null  
3)  唯一约束
           字段名 数据类型 unique  
           或
           unique (字段名1[,字段名2...])  
4)  主键约束
		  字段名 数据类型 primary key  
		  或
		  primary key(字段名1[,字段名2...])  
		  原理:
			 通过  
			索引键值对 ，primary key 'id' (id)  
5) mysql校隊字符集
	show collation; //查找校隊字符集  
	以_cl結尾的不區分大小寫，_cs 區分大小寫，_bin 二進制文件
	show variables like 'character%'; // 查看mysql內部設置  
	+--------------------------+----------------------------+  
	| Variable_name            | Value                      |  
	+--------------------------+----------------------------+  
	| character_set_client     | utf8                       |  
	| character_set_connection | utf8                       |  
	| character_set_database   | utf8mb4                    |  
	| character_set_filesystem | binary                     |  
	| character_set_results    | utf8                       |  
	| character_set_server     | utf8mb4                    |  
	| character_set_system     | utf8                       |  
	| character_sets_dir       | /usr/share/mysql/charsets/ |  
	+--------------------------+----------------------------+    

  
--- comment 註釋  
--- auto_increment 自動增長    
  
create table test(    
		id int unsigned not null key auto_increment, 		//用戶id    
		username varchar(20) not null, 						//名字  
				mobile char(11) not null, 							//電話號碼    
				gender enum('男','女', '保密') not null, 			//使用枚舉類型定義三種情況    
				reg_time timestamp default current_timestamp);      //設置默認插入時間    
## 实体和属性的结构为逻辑数据库  

--创建外键

create table test(    
		id int unsigned not null key auto_increment, 		//用戶id    
		username varchar(20) not null, 						//名字  
				mobile char(11) not null, 							//電話號碼    
				ra class_zd,
				foreign key(clazz_id) refern clazz(id);   //外建  
				gender enum('男','女', '保密') not null, 			//使用枚舉類型定義三種情況    
				reg_time timestamp default current_timestamp);      //設置默認插入時間    
foreign key (建名) refern 表名(列表)


# 比较运算符
 =  等于
 <>,!=  不等于
 > 	大于
