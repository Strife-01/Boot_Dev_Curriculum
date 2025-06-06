SELECT "country_code", ROUND(AVG("age")) AS "average_age"
FROM "users"
GROUP BY "country_code";
