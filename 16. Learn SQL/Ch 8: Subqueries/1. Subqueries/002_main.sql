SELECT * FROM "transactions"
WHERE "user_id" == (
  SELECT "user_id"
  FROM "users"
  WHERE "name" == 'David'
);
