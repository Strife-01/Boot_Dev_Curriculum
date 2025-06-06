ALTER TABLE "people" RENAME TO "users";
ALTER TABLE "users" RENAME COLUMN "tag" TO "username";
ALTER TABLE "users" ADD COLUMN "password" TEXT;
