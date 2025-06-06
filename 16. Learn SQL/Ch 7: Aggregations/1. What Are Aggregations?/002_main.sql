SELECT COUNT(*) AS "successful_transactions"
FROM "transactions"
WHERE "user_id" == 6 AND "was_successful" == true;
