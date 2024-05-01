# Write your MySQL query statement below

select person_name from
queue
inner join
(
select max(turn) as turn from 
    (
    Select *,(case when cumwt <= 1000 then 1 else 0 end) as flag
    from
        (
        select *,SUM(weight) over (order by turn asc) as cumwt
        from queue
        ) t0
    ) t1
where flag = 1
group by flag
) B
on queue.turn = B.turn ;