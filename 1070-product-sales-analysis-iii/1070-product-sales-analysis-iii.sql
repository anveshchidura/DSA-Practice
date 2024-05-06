# Write your MySQL query statement below

select product_id, year as first_year, quantity, price from
(
    select *,
    Dense_Rank() over (partition by product_id order by year asc) as flag
    from sales
) A
where flag=1