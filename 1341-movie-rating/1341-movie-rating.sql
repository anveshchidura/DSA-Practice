# Write your MySQL query statement below

with cte as
(
select A.movie_id, A.user_id, A.rating, A.created_at,B.title,C.name from
movierating A
left join 
movies B
on A.movie_id = B.movie_id
left join 
users C
on A.user_id = C.user_id
)

select results from 
(
select user_id as id,name as results,count(distinct movie_id)
from cte
group by user_id,name
order by 3 desc,name asc
limit 1
) A
union all

select results from 
(
select movie_id as id,title as results,avg(rating) from 
cte
where left(created_at,7) = '2020-02'
group by movie_id,title
order by 3 desc,title asc
limit 1
) B