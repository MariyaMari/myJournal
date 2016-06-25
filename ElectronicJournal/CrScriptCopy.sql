create table disciplina(id_dis integer primary key, n_dis varchar(100) unique);

create table facultet(id_fac integer primary key, n_fac varchar(100) unique);

create table specialty(id_spec integer primary key, n_spec varchar(100) unique, id_fac integer references facultet(id_fac) on update cascade on delete cascade);

create table students(id_st integer primary key, fio varchar(100) unique);

create table gruppa(id_gr integer primary key, n_gr varchar(100) unique, _year integer, id_spec integer references specialty(id_spec) on update cascade on delete cascade);


create table plan(id_spec integer references specialty(id_spec) on update cascade on delete cascade, id_dis integer references disciplina(id_dis) on update cascade on delete cascade, semes integer, primary key(id_spec, id_dis, semes));

create table sostavgr(semes integer, id_gr integer references gruppa(id_gr) on update cascade on delete cascade, id_st integer references students(id_st) on update cascade on delete cascade, primary key(semes, id_gr, id_st));

