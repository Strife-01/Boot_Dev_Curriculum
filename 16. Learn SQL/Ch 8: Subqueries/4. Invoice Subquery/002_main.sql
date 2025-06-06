SELECT * FROM "users"
WHERE "is_admin" == false AND "id" IN (
  SELECT "sender_id" FROM "transactions"
  WHERE "note" LIKE '%invoice%' OR "note" LIKE '%tax%');
