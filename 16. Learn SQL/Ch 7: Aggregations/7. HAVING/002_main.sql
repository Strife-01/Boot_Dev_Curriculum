SELECT "sender_id", SUM("amount") AS "balance"
FROM "transactions"
WHERE "sender_id" IS NOT NULL AND "was_successful" == true AND "note" LIKE '%lunch%'
GROUP BY "sender_id"
HAVING "balance" > 20
ORDER BY "balance";

