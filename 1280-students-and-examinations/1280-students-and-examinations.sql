# Write your MySQL query statement below


select A.student_id,A.student_name,B.subject_name,count(C.subject_name) as attended_exams
from students A
cross join 
subjects B
left join examinations C
on A.student_id = C.student_id and B.subject_name = C.subject_name
group by 1,2,3
order by student_id,student_name;
