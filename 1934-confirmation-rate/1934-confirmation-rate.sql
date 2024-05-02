# Write your MySQL query statement below


select coalesce(A.user_id,B.user_id) as user_id ,(case when confirm is not null then round(confirm/con,2) else 0 end) as confirmation_rate from
signups A
left join
(
select user_id,count(*) as con
from Confirmations
group by 1
) as B
on A.user_id = B.user_id
left join
(
select user_id,count(*) as confirm
from Confirmations
where action = 'confirmed'
group by 1
) as C
on B.user_id = C.user_id;
