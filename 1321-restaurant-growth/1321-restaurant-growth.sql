# Write your MySQL query statement below

with cust1 as (
select visited_on,sum(amount) as tot,count(*) as cnt from
customer
group by visited_on
)

select visited_on,amount,round(amount/7,2) as average_amount  from
(
select visited_on,
SUM(tot) over (ORDER BY visited_on asc ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount
from cust1
) A
where visited_on > DATE_ADD((select min(visited_on) from customer), INTERVAL 5 DAY);


