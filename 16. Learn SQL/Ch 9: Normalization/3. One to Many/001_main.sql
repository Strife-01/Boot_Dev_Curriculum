CREATE TABLE users (
  id INTEGER PRIMARY KEY,
  name TEXT NOT NULL,
  age INTEGER NOT NULL,
  username TEXT UNIQUE NOT NULL,
  password TEXT NOT NULL,
  is_admin BOOLEAN
);

CREATE TABLE "countries" (
  "id" INTEGER PRIMARY KEY,
  "country_code" TEXT NOT NULL,
  "name" TEXT NOT NULL,
  "user_id" INTEGER NOT NULL,
  CONSTRAINT "fk_users" FOREIGN KEY ("user_id")
    REFERENCES "users"("id")
);
