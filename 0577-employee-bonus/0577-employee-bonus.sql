# Write your MySQL query statement below



select A.name,B.bonus from
Employee A
left join Bonus B
on A.empid = B.empid 
where bonus < 1000 or bonus is null
