use school
select * from class;

use school
create table chengji(
    cj_id int,
    cj_count FLOAT(4,1) COMMENT "分数",
    kid int COMMENT  "课程id",
    stuid int COMMENT "学生id"
);


desc chengji;

INSERT INTO chengji   values(1,122.1,1,123);
select * from chengji;

INSERT into 