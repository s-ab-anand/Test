#ifndef BADNEIGHBOR_H
#define BADNEIGHBOR_H


class BadNeighbor
{
    public:
        /** Default constructor */
        BadNeighbor();
        /** Access array
         * \return The current value of array
         */
        Vector Getarray() { return array; }
        /** Set array
         * \param val New value to set
         */
        void Setarray(Vector val) { array = val; }
    protected:
    private:
        Vector array; //!< Member variable "array"
};

#endif // BADNEIGHBOR_H
