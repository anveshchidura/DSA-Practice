SELECT MAX(E2.salary) AS SecondHighestSalary
FROM Employee AS E1
LEFT JOIN Employee AS E2 ON E1.salary > E2.salary
