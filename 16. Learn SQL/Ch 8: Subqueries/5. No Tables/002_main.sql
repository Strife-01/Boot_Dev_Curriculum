SELECT *, ROUND("age_in_days" / 365) AS "age" FROM "users"
WHERE "age" >= 40;
