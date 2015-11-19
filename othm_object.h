#ifndef OTHM_OBJECT_H
#define OTHM_OBJECT_H

struct othm_obj_tag {
	int mutability;
	void *type;
	void *container;
	void *data_form;
	/* struct othm_symbol_struct *destructor; */
	/* struct othm_symbol_struct *printer; */
};

#endif
