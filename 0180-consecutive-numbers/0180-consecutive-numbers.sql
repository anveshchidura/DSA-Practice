# Write your MySQL query statement below


select distinct A.num as ConsecutiveNums
from
logs A
inner join
logs B
inner join
logs C
on A.num = B.num and A.num = C.num and
B.id = A.id + 1 and C.id = B.id + 1



