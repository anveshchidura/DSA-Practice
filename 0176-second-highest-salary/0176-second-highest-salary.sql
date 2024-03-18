SELECT  
(
SELECT distinct A1.salary AS SecondHighestSalary
FROM (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as flag
    FROM Employee
) AS A1
WHERE A1.flag = 2
) 
as SecondHighestSalary;
