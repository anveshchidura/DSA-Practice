# Write your MySQL query statement below

select id,sum(flag) as num
from
(
select requester_id as id, 1 as flag
from RequestAccepted
union all
select accepter_id as id, 1 as flag
from RequestAccepted
) as A
group by id 
order by num Desc
limit 1;