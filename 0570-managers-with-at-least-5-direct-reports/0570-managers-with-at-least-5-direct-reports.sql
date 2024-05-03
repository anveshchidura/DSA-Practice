# Write your MySQL query statement below

select  name from employee A
inner join
(
select managerId,count(distinct id) as unicnt
from employee
group by managerId
having unicnt >=5
) B
on A.id = B.managerId