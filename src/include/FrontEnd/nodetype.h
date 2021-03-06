#ifndef _NODETYPE_H_
#define _NODETYPE_H_
/* definition of Node data structure */
typedef enum {
  /* expression nodes */
  Const, Id, Binop, Unary, Cast, Comma, Ternary, Array, Call, Initializer,
  ImplicitCast,
  /* statement nodes */
  Label, Switch, Case, Default, If, IfElse, While, Do, For, Goto, Continue,
  Break, Return, Block,
  /* type nodes */
  Prim, Tdef, Ptr, Adcl, Fdcl, Sdcl, Udcl, Edcl,
  /* declaration node */
  Decl,
  /* GCC __attribute__ extension */
  Attrib,
  /* procedure def node */
  Proc,
  /* random text and preprocessor command node */
  Text,
  /*----------12----SPL node----------*/
  STRdcl,		/*stream SPL*/
  Comdcl,		/*composite SPL*/
  Composite,	/* composite def node SPL*/
  ComInOut,		/*composite SPL*/
  ComBody,		/*composite.block SPL*/
  Param,		/*composite.body.param SPL*/
  OperBody,		/*operator SPL*/
  Operdcl,		/*operator SPL*/
  Operator_,	/* operator def node SPL*/
  Window,		/*operator.body.window SPL*/
  Sliding,		/*sliding window SPL*/
  Tumbling,		/*tumbling window SPL*/

  /*-------7-------New For SPL----------*/
  CompositeCall,/*composite.head.inout.stream.id SPL*/
  Pipeline,
  SplitJoin,
  Split,
  Join,
  RoundRobin,
  Duplicate,

  /********1********新文法**********/
  Add,Uncertainty
  /*
  删除掉的节点： Var,Graph,StreamFor,StreamIf,StreamIfElse,Eviction,Trigger,logic
  修改过的节点： comBodyNode,PipelineNode,SplitJoinNode,slidingNode,tumblingNode
  新增加的节点： Add
  */
} NodeType;

#endif
