#ifndef CTRANSACTION_H
#define CTRANSACTION_H

/**
 * @brief The CTransaction class is interface of transaction.
 *
 * This is command pattern.
 */
class CTransaction {
  public:
    /**
     * @brief CTransaction constructor.
     */
    CTransaction() {}
    /**
     * @brief Execute is call to confirm transaction.
     */
    virtual void Execute() = 0;
};

#endif // CTRANSACTION_H
