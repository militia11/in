#ifndef CTRANSACTION_H
#define CTRANSACTION_H

class CTransaction {
	public:
		CTransaction() {}
		virtual void Execute() = 0;
};

#endif // CTRANSACTION_H
