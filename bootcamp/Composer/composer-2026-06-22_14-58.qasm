OPENQASM 2.0;
include "qelib1.inc";

qreg q[2];
creg c[2];
id q[1];
x q[0];
h q[0];
h q[1];
barrier q[0], q[1];
id q[0];
id q[1];
barrier q[0], q[1];
h q[1];
measure q[1] -> c[1];
