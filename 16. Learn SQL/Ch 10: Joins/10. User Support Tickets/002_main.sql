SELECT u.name, u.username, COUNT(t.id) AS "support_ticket_count"
FROM users u INNER JOIN support_tickets t ON u.id == t.user_id
WHERE t.issue_type != 'Account Access'
GROUP BY u.username HAVING "support_ticket_count" > 0
ORDER BY "support_ticket_count" DESC;
