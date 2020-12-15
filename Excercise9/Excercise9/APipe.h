#pragma once
#ifndef A_PIPE_H
#define A_PIPE_H

enum Type {
    EAST_WEST,
    NORTH_SOUTH,
    NORTH_SOUTH_EAST_WEST,
    EMPTY,
    END,
    SOUTH_EAST_WEST
};

struct ATube;

struct IPipe {
    virtual ~IPipe(){};
    virtual const ATube* getTube(int x, int y) const = 0;
    virtual bool isPipeOk() const = 0;
    virtual int getSize() const = 0;
};

struct ATube {
    virtual ~ATube(){};
    virtual bool isValid(const IPipe* pipe) const = 0;
    virtual const Type getType() const = 0;
    int x;
    int y;
    virtual char toString() const = 0;
};

class Pipe :public IPipe {
private:
    ATube*** matrix;
    int size;
public:
    Pipe(const int size);
    ~Pipe();
    void addTube(int x, int y, ATube* tube);
    const ATube* getTube(int x, int y);
    bool isPipeOk() const override;
    int getSize() const override;
    void toString() const;
};

class Tube : public ATube {
private:
    Type type;
public:
    Tube(int x, int y, Type type);
    ~Tube();
    bool isValid(const IPipe* pipe) const override;
    const Type getType() const override;
    char toString() const override;
};

#endif // !A_PIPE_H

