insert into disciplina values(1, 'Математика');
insert into disciplina values(2, 'Информатика');
insert into disciplina values(3, 'Программирование');

insert into facultet values(1, 'ФКФН');
insert into facultet values(2, 'ФАИТ');
insert into facultet values(3, 'ФАД');

insert into specialty values(1, 'Программная инженерия', 1);
insert into specialty values(2, 'Финансы и кредит', 2);
insert into specialty values(3, 'Архитектура', 3);

insert into students values(12, 'Иванов П.И.');
insert into students values(22, 'Петров И.С.');
insert into students values(32, 'Сидоров Р.Е.');

insert into typerabot values(13, 'Лекция');
insert into typerabot values(23, 'Практика');
insert into typerabot values(33, 'Лабораторная');

insert into gruppa values(14, 'ПО-11', 2011, 1);
insert into gruppa values(24, 'ПО-21', 2012, 2);
insert into gruppa values(34, 'ПО-31', 2013, 3);


insert into plan values(1, 1, 3);
insert into plan values(1, 2, 5);
insert into plan values(2, 2, 5);
insert into plan values(3, 3, 7);

insert into sostavgr values(2, 14, 12);
insert into sostavgr values(2, 14, 22);
insert into sostavgr values(4, 24, 22);
insert into sostavgr values(6, 34, 32);

insert into link3 values(12, '2016-01-01', 13, 0, 1);
insert into link3 values(22, '2016-01-02', 23, 1, 2);
insert into link3 values(32, '2016-01-03', 33, 2, 3);

insert into link1 values(1, 'Работа А', 1, 13, 3, 1, 1, 20, 1);
insert into link1 values(2, 'Работа Б', 2, 23, 5, 2, 2, 40, 2);
insert into link1 values(3, 'Работа В', 3, 33, 7, 3, 1, 50, 3);

insert into link2 values('2016-01-01', 12, 1);
insert into link2 values('2016-01-02', 22, 2);
insert into link2 values('2016-01-03', 32, 3);
