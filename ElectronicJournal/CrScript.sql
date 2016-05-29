create table disciplina(id_dis integer primary key, n_dis varchar(100) unique);

create table facultet(id_fac integer primary key, n_fac varchar(100) unique);

create table specialty(id_spec integer primary key, n_spec varchar(100) unique, id_fac integer references facultet(id_fac) on update cascade on delete cascade);

create table students(id_st integer primary key, fio varchar(100) unique);

create table typerabot(id_trab integer primary key, n_trab varchar(100) unique);

create table gruppa(id_gr integer primary key, n_gr varchar(100) unique, _year integer, id_spec integer references specialty(id_spec) on update cascade on delete cascade);


create table plan(id_spec integer references specialty(id_spec) on update cascade on delete cascade, id_dis integer references disciplina(id_dis) on update cascade on delete cascade, semes integer, primary key(id_spec, id_dis, semes));

create table sostavgr(semes integer, id_gr integer references gruppa(id_gr) on update cascade on delete cascade, id_st integer references students(id_st) on update cascade on delete cascade, primary key(semes, id_gr, id_st));

create table link3(id_st integer references students(id_st) on update cascade on delete cascade, data varchar(12), id_trab integer references typerabot(id_trab) on update cascade on delete cascade, otm integer, id_dis integer references disciplina(id_dis) on update cascade on delete cascade, primary key(id_st, data, id_trab, id_dis));

create table link1(id_spec integer references specialty(id_spec) on update cascade on delete cascade, n_rab varchar(100) unique, rabn integer unique, id_trab integer references typerabot(id_trab) on update cascade on delete cascade, semes integer, id_dis integer references disciplina(id_dis) on update cascade on delete cascade, nedel integer, rang integer, id_lin1 unique, primary key(id_spec, rabn, id_trab, semes, id_dis));

create table link2(data varchar(12), id_st integer references students(id_st) on update cascade on delete cascade, id_lin1 integer references link1(id_lin1) on update cascade on delete cascade, primary key(id_st, id_lin1));

