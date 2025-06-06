SELECT *, IIF("age" >= 55 OR "country_code" == 'CA', true, false) AS "discount_eligible"
FROM "users";
