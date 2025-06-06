SELECT u.id, u.name, u.age, u.username, c.name AS country_name, SUM(t."amount") AS "balance"
FROM transactions t INNER JOIN users u ON u.id == t.user_id INNER JOIN countries c ON u.country_code == c.country_code
WHERE u.id == 6;
