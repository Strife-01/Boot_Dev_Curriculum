SELECT "user_id", SUM("amount") AS "balance"
FROM "transactions"
GROUP BY "user_id";
