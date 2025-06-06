CREATE TABLE "transactions" (
  "id" INTEGER PRIMARY KEY,
  "sender_id" INTEGER,
  "recipient_id" INTEGER NOT NULL,
  "memo" TEXT NOT NULL,
  "amound" INTEGER NOT NULL,
  "balance" INTEGER NOT NULL
);
