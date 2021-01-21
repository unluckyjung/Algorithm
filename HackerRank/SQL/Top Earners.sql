SELECT salary * months AS totalEarning, COUNT(*) FROM Employee
-- COUNT(salary * months) also Ok
-- But COUNT(totalEarning) is impossible
GROUP BY totalEarning
ORDER BY totalEarning DESC LIMIT 1;