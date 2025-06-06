CREATE TABLE transactions (
  id INTEGER, 
  recipient_id INTEGER, 
  sender_id INTEGER, 
  note TEXT, 
  amount INTEGER
);

ALTER TABLE transactions
ADD COLUMN was_successful BOOLEAN;

ALTER TABLE transactions
ADD COLUMN transaction_type TEXT;

