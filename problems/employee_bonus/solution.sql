# Write your MySQL query statement below
# SELECT a~name,b~bonus from Employee as a inner join bonus as b where b~bonus<1000;

SELECT a.name, b.bonus
FROM Employee as a
LEFT JOIN Bonus as b ON a.empID = b.empID where b.bonus<1000 or b.bonus is NULL;