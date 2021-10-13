# Write your MySQL query statement below
SELECT a.FirstName,a.LastName,b.City,b.state FROM Person as a left join Address as b
ON a.PersonId = b.PersonId;