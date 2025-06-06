SELECT u.name, SUM(t.amount) AS "sum", COUNT(t.id) AS "num_transactions"
FROM users u
LEFT JOIN transactions t
ON u.id == t.user_id
GROUP BY u.id
ORDER BY "sum" DESC;

