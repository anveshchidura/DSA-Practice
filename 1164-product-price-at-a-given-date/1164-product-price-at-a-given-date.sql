# Write your MySQL query statement below

select product_id,new_price as price from
(
select *,Row_number() over (partition by product_id order by change_date desc) as rk
from products
where change_date <= '2019-08-16'
) A
where rk = 1
union all
select product_id,10 as price
from products
group by 1,2
having min(change_date) > '2019-08-16';