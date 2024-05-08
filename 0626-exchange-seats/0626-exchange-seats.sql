# Write your MySQL query statement below


select id,
case 
when id%2=0 then lag_student
when id%2=1 and lead_student is not null then lead_student
else student
end as student
from
(
select *,lag(student) over (order by id) as lag_student,
lead(student) over (order by id) as lead_student
from seat
) A
order by id asc;